// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#pragma once

#include <QPixmap>
#include <QString>
#include <QVariant>

class CaptureRequest
{
public:
    enum CaptureMode
    {
        FULLSCREEN_MODE,
        GRAPHICAL_MODE,
        SCREEN_MODE,
    };

    enum ExportTask
    {
        NO_TASK = 0,
        COPY = 1,
        SAVE = 2,
        PRINT_RAW = 4,
        PRINT_GEOMETRY = 8,
        PIN = 16,
        UPLOAD = 32,
        ACCEPT_ON_SELECT = 64,
    };

    // delay: delay before the capture UI is shown (existing behavior)
    // delayAfterSelection: delay after the user accepts the selection and
    // before the actual export/capture is performed. Default 0 for backwards
    // compatibility.
    CaptureRequest(CaptureMode mode,
                   const uint delay = 0,
                   QVariant data = QVariant(),
                   ExportTask tasks = NO_TASK,
                   const uint delayAfterSelection = 0);

    void setStaticID(uint id);
    void setDelayAfterSelection(uint delayMs);

    uint id() const;
    uint delay() const;
    uint delayAfterSelection() const;
    QString path() const;
    QVariant data() const;
    CaptureMode captureMode() const;
    ExportTask tasks() const;
    QRect initialSelection() const;

    void addTask(ExportTask task);
    void removeTask(ExportTask task);
    void addSaveTask(const QString& path = QString());
    void addPinTask(const QRect& pinWindowGeometry);
    void setInitialSelection(const QRect& selection);

private:
    CaptureMode m_mode;
    uint m_delay;
    uint m_delayAfterSelection{ 0 };
    QString m_path;
    ExportTask m_tasks;
    QVariant m_data;
    QRect m_pinWindowGeometry, m_initialSelection;

    CaptureRequest() {}
};

using eTask = CaptureRequest::ExportTask;

inline eTask operator|(const eTask& a, const eTask& b)
{
    return static_cast<eTask>(static_cast<int>(a) | static_cast<int>(b));
}

inline eTask operator&(const eTask& a, const eTask& b)
{
    return static_cast<eTask>(static_cast<int>(a) & static_cast<int>(b));
}

inline eTask& operator|=(eTask& a, const eTask& b)
{
    a = static_cast<eTask>(static_cast<int>(a) | static_cast<int>(b));
    return a;
}
