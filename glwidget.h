#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <limits>
#include "camera.h"
#include "light.h"
#include "material.h"
#include "trackball.h"
#include <vector>

class GLWidget : public QGLWidget
{
        Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    virtual ~GLWidget();

signals:
    void statusBarMessage(QString ns);

public slots:
    void toggleBackgroundColor(bool toBlack);
    void showFileOpenDialog();

protected:
    void initializeGL();
    void resizeGL(int width , int height);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);


private:
    void createVBOs();
    void genTangents();
    void destroyVBOs();
    void createShaders();
    void destroyShaders();
    void readOFFFile(const QString &fileName);
    void genNormals();
    void genTexCoordsCylinder();
    unsigned int numVertices;
    unsigned int numFaces;
    QVector4D *vertices;
    QVector3D *normals;
    QVector2D *texCoords;
    QVector4D *tangents;
    std::vector<unsigned int> indices;
    QGLBuffer *vboVertices;
    QGLBuffer *vboNormals;
    QGLBuffer *vboTexCoords;
    QGLBuffer *vboTangents;
    QGLBuffer *vboIndices;
    QGLShader *vertexShader;
    QGLShader *fragmentShader;
    int image;
    QGLShaderProgram *shaderProgram;
    unsigned int currentShader;
    int texID[2];
    QMatrix4x4 modelViewMatrix;
    QMatrix4x4 projectionMatrix;
    Camera camera;
    Light light;
    Material material;
    TrackBall trackBall;
    double zoom;
    QTimer timer;
};

#endif // GLWIDGET_H
