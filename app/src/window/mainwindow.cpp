#include "app/include/window/mainwindow.h"
#include "../../window/ui_mainwindow.h"

#include <iostream>
#include <stdexcept>

#include <QImage>

VisualFlow::VisualFlow(QWidget * parent)
: QMainWindow(parent), ui_(new Ui::VisualFlow), scene_(std::make_shared<QGraphicsScene>())
{
  ui_->setupUi(this);
  display_video_stopped_text();
}

VisualFlow::~VisualFlow() { delete ui_; }

void VisualFlow::on_startPushButton_clicked()
{
  cap_ = cv::VideoCapture(0);

  if (!cap_.isOpened())
  {
    throw std::runtime_error("Could not open capture device.");
  }

  capture_ = true;
  QGraphicsPixmapItem * item;
  while (capture_ && cap_.isOpened())
  {
    cap_ >> cv_image_;
    if (!cv_image_.empty())
    {
      item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(
        (unsigned char *)cv_image_.data, cv_image_.cols, cv_image_.rows, QImage::Format_RGB888)));
      scene_->addItem(item);
      ui_->graphicsView->setScene(scene_.get());
      ui_->graphicsView->show();
    }
    qApp->processEvents();
  }
  cap_.release();
  display_video_stopped_text();
}

void VisualFlow::display_video_stopped_text()
{
  scene_->addText("Video stopped.");
  ui_->graphicsView->setScene(scene_.get());
  ui_->graphicsView->show();
}

void VisualFlow::on_stopPushButton_clicked() { capture_ = false; }

void VisualFlow::closeEvent(QCloseEvent * event) { capture_ = false; }
