// SPDX-License-Identifier: GPL-3.0-or-later

// Minimal DelaySubTool stub
#include "delaysubtool.h"

DelaySubTool::DelaySubTool(QObject* parent)
  : AbstractActionTool(parent)
{}
bool DelaySubTool::closeOnButtonPressed() const
{
    return false;
}
QIcon DelaySubTool::icon(const QColor& background, bool) const
{
    return QIcon(iconPath(background) + QStringLiteral("timer-subtract.svg"));
}
QString DelaySubTool::name() const
{
    return tr("Delay -");
}
QString DelaySubTool::description() const
{
    return tr("Decrease post-capture delay by one second");
}
CaptureTool::Type DelaySubTool::type() const
{
    return CaptureTool::TYPE_DELAY_DECREASE;
}
CaptureTool* DelaySubTool::copy(QObject* parent)
{
    return new DelaySubTool(parent);
}
void DelaySubTool::pressed(CaptureContext&)
{
    emit requestAction(CaptureTool::REQ_DELAY_DECREASE);
}
