// Copyright (C) 2019 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QGuiApplication>
#include <QNetworkInterface>
#include <QQmlApplicationEngine>
#include <QQmlContext>

static QStringList availableHosts()
{
    QStringList hosts;

    const auto networkInterfaces = QNetworkInterface::allInterfaces();
    for (const auto &interface : networkInterfaces)
        for (const auto &address : interface.addressEntries())
            hosts.push_back(address.ip().toString());

    return hosts;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Qt CoAP Example");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("hostsModel", availableHosts());

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(1); },
                     Qt::QueuedConnection);
    engine.loadFromModule("CoapSecureClientModule", "Main");

    return app.exec();
}
