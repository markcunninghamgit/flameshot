// DelayWidget - minimal header
#pragma once

#include <QWidget>

class DelayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DelayWidget(QWidget* parent = nullptr)
      : QWidget(parent)
    {}
    void setSeconds(int) {}
    int seconds() const { return 0; }

signals:
    void start(int seconds);
    void cancelled();
};
