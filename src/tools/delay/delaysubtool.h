// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "src/tools/abstractactiontool.h"

class DelaySubTool : public AbstractActionTool
{
    Q_OBJECT
public:
    explicit DelaySubTool(QObject* parent = nullptr);

    bool closeOnButtonPressed() const override;

    QIcon icon(const QColor& background, bool inEditor) const override;
    QString name() const override;
    CaptureTool::Type type() const override;
    QString description() const override;
    CaptureTool* copy(QObject* parent = nullptr) override;

    void pressed(CaptureContext& context) override;
};
