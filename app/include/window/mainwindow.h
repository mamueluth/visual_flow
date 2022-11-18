#ifndef VISUALFLOW_H
#define VISUALFLOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class VisualFlow;
}
QT_END_NAMESPACE

class VisualFlow : public QMainWindow
{
  Q_OBJECT

public:
  VisualFlow(QWidget * parent = nullptr);
  ~VisualFlow();

private:
  Ui::VisualFlow * ui;
};
#endif  // VISUALFLOW_H
