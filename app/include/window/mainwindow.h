#ifndef VISUALFLOW_H
#define VISUALFLOW_H

#include <memory>

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QPixmap>

#include <opencv2/opencv.hpp>

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

private slots:
  void on_startPushButton_clicked();
  void on_stopPushButton_clicked();

protected:
  void closeEvent(QCloseEvent * event);

private:
  void display_video_stopped_text();

  std::shared_ptr<QGraphicsScene> scene_;
  std::shared_ptr<QGraphicsPixmapItem> qt_pixmap_;

  cv::Mat cv_image_;
  cv::VideoCapture cap_;
  bool capture_ = false;

  Ui::VisualFlow * ui_;
};
#endif  // VISUALFLOW_H
