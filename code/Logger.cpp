/********************************************************************************
> FileName:	Logger.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Wed Apr 14 10:45:26 2021
********************************************************************************/

#include "Logger.h"
#include <QString>

void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& message)
{
	auto log = message.toLocal8Bit();
	switch(type)
	{
		case QtDebugMsg:
			fprintf(stderr, "Debug %s (%s:%u %s)\n", log.constData(), context.file, context.line, context.function);
			break;
		case QtInfoMsg:
			fprintf(stderr, "Info %s (%s:%u %s)\n", log.constData(), context.file, context.line, context.function);
			break;
		case QtWarningMsg:
			fprintf(stderr, "Warning %s (%s:%u %s)\n", log.constData(), context.file, context.line, context.function);
			break;
		case QtCriticalMsg:
			fprintf(stderr, "Critical %s (%s:%u %s)\n", log.constData(), context.file, context.line, context.function);
			break;
		case QtFatalMsg:
			fprintf(stderr, "Fatal %s (%s:%u %s)\n", log.constData(), context.file, context.line, context.function);
			break;
	}
}
