#include <QApplication>
#include <QtGlobal>
#include <QMutex>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

QString fileName()
{
	auto current = QDateTime::currentDateTime();
	QString s = QString("%1.log").arg(current.toString("yyyy-MM-dd"));
	return s;
}



void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QString text;
	switch(type)
	{
		case QtDebugMsg:
			text = QString("Debug:");
			break;
		case QtWarningMsg:
			text = QString("Warning:");
			break;
		case QtCriticalMsg:
			text = QString("Critical:");
			break;
		case QtFatalMsg:
			text = QString("Fatal:");
	}

	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);
#ifndef NDEBUG
	QFile file;
	file.open(stderr, QIODevice::WriteOnly|QIODevice::Append);
#else
	QFile file(fileName());
	file.open(QIODevice::WriteOnly | QIODevice::Append);
#endif
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	qInstallMessageHandler(outputMessage);
	qDebug("This is a debug message");
	//qWarning("This is a warning message");
	//qCritical("This is a critical message");
	//qFatal("This is a fatal message");
	return app.exec();
}
