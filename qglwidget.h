#ifndef QGLWIDGET_H
#define QGLWIDGET_H

#include <QWidget>

class QGLWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QGLWidget(QWidget *parent = nullptr);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

signals:

};

#endif // QGLWIDGET_H
