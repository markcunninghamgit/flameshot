// SPDX-License-Identifier: GPL-3.0-or-later

// Minimal DelayAddTool stub
#include "delayaddtool.h"

DelayAddTool::DelayAddTool(QObject* parent)
  : AbstractActionTool(parent)
{}
bool DelayAddTool::closeOnButtonPressed() const
{
    return false;
}
QIcon DelayAddTool::icon(const QColor& background, bool) const
{
    return QIcon(iconPath(background) + QStringLiteral("timer-add.svg"));
}
QString DelayAddTool::name() const
{
    return tr("Delay +");
}
QString DelayAddTool::description() const
{
    return tr("Increase post-capture delay by one second");
}
CaptureTool::Type DelayAddTool::type() const
{
    return CaptureTool::TYPE_DELAY_INCREASE;
}
CaptureTool* DelayAddTool::copy(QObject* parent)
{
    return new DelayAddTool(parent);
}
void DelayAddTool::pressed(CaptureContext&)
{
    emit requestAction(CaptureTool::REQ_DELAY_INCREASE);
}
