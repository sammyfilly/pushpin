/*
 * Copyright (C) 2016 Fanout, Inc.
 *
 * This file is part of Pushpin.
 *
 * $FANOUT_BEGIN_LICENSE:APACHE2$
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * $FANOUT_END_LICENSE$
 */

#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QStringList>

class Service : public QObject
{
	Q_OBJECT

public:
	Service(QObject *parent = 0);
	~Service();

	QString name() const;

	virtual QStringList arguments() const = 0;
	virtual bool acceptSighup() const;
	virtual bool isStarted() const;

	virtual bool preStart();
	virtual void start();
	virtual void postStart();
	virtual void stop();
	virtual void postStop();
	virtual QString formatLogLine(const QString &line) const;

	void sendSighup();

protected:
	void setName(const QString &name);
	void setStandardOutputFile(const QString &file);
	void setPidFile(const QString &file);

signals:
	void started();
	void stopped();
	void logLine(const QString &line);
	void error(const QString &message);

private:
	class Private;
	Private *d;
};

#endif
