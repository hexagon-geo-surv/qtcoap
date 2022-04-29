/****************************************************************************
**
** Copyright (C) 2017 Witekio.
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCoap module.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
******************************************************************************/

#ifndef QCOAPREPLY_H
#define QCOAPREPLY_H

#include <QtCoap/qcoapmessage.h>
#include <QtCoap/qcoaprequest.h>
#include <QtCoap/qcoapglobal.h>
#include <QtCoap/qcoapnamespace.h>
#include <QtCore/qiodevice.h>

QT_BEGIN_NAMESPACE

class QCoapInternalReply;
class QCoapReplyPrivate;
class Q_COAP_EXPORT QCoapReply : public QIODevice
{
    Q_OBJECT
public:
    ~QCoapReply() override;

    QtCoap::ResponseCode responseCode() const;
    QCoapMessage message() const;
    QCoapRequest request() const;
    QUrl url() const;
    QtCoap::Method method() const;
    QtCoap::Error errorReceived() const;
    bool isRunning() const;
    bool isFinished() const;
    bool isAborted() const;
    bool isSuccessful() const;
    void abortRequest();

Q_SIGNALS:
    void finished(QCoapReply *reply);
    void notified(QCoapReply *reply, const QCoapMessage &message);
    void error(QCoapReply *reply, QtCoap::Error error);
    void aborted(const QCoapToken &token);

protected:
    qint64 readData(char *data, qint64 maxSize) override;
    qint64 writeData(const char *data, qint64 maxSize) override;

    Q_DECLARE_PRIVATE(QCoapReply)
    Q_PRIVATE_SLOT(d_func(), void _q_setRunning(const QCoapToken &, QCoapMessageId))
    Q_PRIVATE_SLOT(d_func(), void _q_setContent(const QHostAddress &host, const QCoapMessage &,
                                                QtCoap::ResponseCode))
    Q_PRIVATE_SLOT(d_func(), void _q_setNotified())
    Q_PRIVATE_SLOT(d_func(), void _q_setObserveCancelled())
    Q_PRIVATE_SLOT(d_func(), void _q_setFinished(QtCoap::Error))
    Q_PRIVATE_SLOT(d_func(), void _q_setError(QtCoap::ResponseCode))
    Q_PRIVATE_SLOT(d_func(), void _q_setError(QtCoap::Error))

private:
    explicit QCoapReply(QCoapReplyPrivate &dd, QObject *parent = nullptr);
    friend class QCoapResourceDiscoveryReply;
};

QT_END_NAMESPACE

#endif // QCOAPREPLY_H
