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

#ifndef QCOAPRESOURCE_P_H
#define QCOAPRESOURCE_P_H

#include <QtCoap/qcoapresource.h>
#include <QtCore/qshareddata.h>
#include <QtNetwork/qhostaddress.h>

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists purely as an
// implementation detail. This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

QT_BEGIN_NAMESPACE

class Q_AUTOTEST_EXPORT QCoapResourcePrivate : public QSharedData
{
public:
    QCoapResourcePrivate() {}
    QCoapResourcePrivate(const QCoapResourcePrivate &other)
      : QSharedData(other), maximumSize(other.maximumSize), contentFormat(other.contentFormat)
      , resourceType(other.resourceType), interface(other.interface), host(other.host)
      , path(other.path), title(other.title), observable(other.observable) {}
    ~QCoapResourcePrivate() {}

    int maximumSize = -1;    // sz field
    uint contentFormat = 0;  // ct field
    QString resourceType;    // rt field
    QString interface;       // if field
    QHostAddress host;
    QString path;
    QString title;
    bool observable = false; // obs field
};

QT_END_NAMESPACE

#endif // QCOAPRESOURCE_P_H
