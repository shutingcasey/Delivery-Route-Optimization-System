// log4c.c: Defines the functions for the static library.

#include "log4c.h"
#include <stdarg.h>
#include <time.h>
#include <string.h>


#define MAX_SEVERITY_STR 10

#define L4C_GOOD        0
#define L4C_OPEN_FAILED 1
#define L4C_FILE_CLOSED 2
#define L4C_WRITE_FAILED 4
#define L4C_NULL_LOG     8


void severityToString(char s[], const int severity)
{
	switch (severity)
	{
	case L4C_ERROR:
		strcpy(s, "ERROR");
		break;
	case L4C_WARNING:
		strcpy(s, "WARN");
		break;
	case L4C_INFO:
		strcpy(s, "INFO");
		break;
	default:
		strcpy(s, "?");
		break;
	}
}

struct Log4cStruct l4cOpen(char fileName[], const int append)
{
	struct Log4cStruct log = { 0, 0, 1, 1, L4C_INFO };

	log.logFile = fopen(fileName, append ? "a" : "w");
	if (log.logFile == NULL)
	{
		log.fileStatus = L4C_OPEN_FAILED;
		log.enabled = 0;
	}
	return log;
}

void l4cClose(struct Log4cStruct* log)
{
	if (log != NULL && log->fileStatus == L4C_GOOD && log->logFile)
	{
		fclose(log->logFile);
		log->logFile = NULL;
		log->fileStatus = L4C_FILE_CLOSED;
	}
}

void l4cError(struct Log4cStruct* log, const char msg[])
{
	l4cPrintf(log, L4C_ERROR, "%s", msg);
}

void l4cWarning(struct Log4cStruct* log, const char msg[])
{
	l4cPrintf(log, L4C_WARNING, "%s", msg);
}

void l4cInfo(struct Log4cStruct* log, const char msg[])
{
	l4cPrintf(log, L4C_INFO, "%s", msg);
}

void l4cPrintf(struct Log4cStruct* log, const int severity, const char format[], ...)
{
	if (log == NULL || log->fileStatus != L4C_GOOD || log->logFile == NULL) {
		if (log != NULL)
			log->fileStatus = log->fileStatus | L4C_WRITE_FAILED;
	}
	else if (log->enabled && severity <= log->filter) {
		time_t currTime = time(NULL);
		char now[100 + 1];
		strftime(now, sizeof(now), "[%Y-%m-%d %H:%M:%S]", localtime(&currTime));
		char sev[MAX_SEVERITY_STR + 1];
		severityToString(sev, severity);

		va_list argp;
		va_start(argp, format);
		fprintf(log->logFile, "<%s> %s: ", sev, now);
		vfprintf(log->logFile, format, argp);
		fprintf(log->logFile, "\n");

		if (log->autoFlush)
			fflush(log->logFile);
	}
}

int l4cCheck(const struct Log4cStruct* log, char errMsg[])
{
	int result = 0;

	if (errMsg != NULL) errMsg[0] = '\0';

	if (log != NULL && errMsg != NULL)
	{
		if (log->fileStatus != L4C_GOOD)
		{
			result = log->fileStatus;
			switch (log->fileStatus)
			{
			case L4C_OPEN_FAILED:
			case (L4C_OPEN_FAILED | L4C_WRITE_FAILED):
				strcat(errMsg, "FILE OPEN FAILED");
				break;
			case L4C_FILE_CLOSED:
			case (L4C_FILE_CLOSED | L4C_WRITE_FAILED):
				strcat(errMsg, "FILE HAS BEEN CLOSED");
				break;
			case L4C_WRITE_FAILED:
				strcat(errMsg, "WRITE FILE FAILED");
				break;
			}
		}
	}
	else
	{
		result = L4C_NULL_LOG;
		if (errMsg != NULL) strcpy(errMsg, "Log struct is NULL");
	}

	return result;
}

void l4cDisable(struct Log4cStruct* log)
{
	if (log != NULL) log->enabled = 0;
}

void l4cEnable(struct Log4cStruct* log)
{
	if (log != NULL) log->enabled = 1;
}

int l4cIsEnabled(struct Log4cStruct* log)
{
	int result = -1;
	if (log != NULL) result = log->enabled;
	return result;
}

int l4cFilter(struct Log4cStruct* log, const int severity)
{
	int result = -1;

	if (log != NULL)
	{
		result = log->filter;
		if (severity < L4C_ERROR) log->filter = L4C_ERROR;
		else if (severity > L4C_INFO) log->filter = L4C_INFO;
		else log->filter = severity;
	}

	return result;
}

int l4cGetFilter(const struct Log4cStruct* log)
{
	int result = -1;
	if (log != NULL) result = log->filter;
	return result;
}

void l4cDisableAutoFlush(struct Log4cStruct* log)
{
	if (log != NULL) log->autoFlush = 0;
}

void l4cEnableAutoFlush(struct Log4cStruct* log)
{
	if (log != NULL) log->autoFlush = 1;
}

int l4cIsAutoFlush(const struct Log4cStruct* log)
{
	int result = -1;
	if (log != NULL) result = log->autoFlush;
	return result;
}