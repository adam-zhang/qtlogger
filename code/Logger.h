/********************************************************************************
> FileName:	Logger.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Wed Apr 14 10:45:26 2021
********************************************************************************/
#ifndef __LOGGER__H
#define __LOGGER__H

#include <QtGlobal>


void messageHandler(QtMsgType, const QMessageLogContext&, const QString& msg);

#endif//__LOGGER__H
