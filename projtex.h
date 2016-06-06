#include <QWindow>
#include <QTimer>
#include <QString>
#include <QKeyEvent>

#include <QVector3D>
#include <QMatrix4x4>

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_3_Core>

#include <QOpenGLShaderProgram>

#include "teapot.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)
#define TwoPI (float)(2 * M_PI)

//class MyWindow : public QWindow, protected QOpenGLFunctions_3_3_Core
class MyWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MyWindow();
    ~MyWindow();
    virtual void keyPressEvent( QKeyEvent *keyEvent );    

private slots:
    void render();

private:    
    void initialize();
    void modCurTime();

    void initShaders();
    void CreateVertexBuffer();    
    void initMatrices();

    void PrepareTexture(GLenum TextureUnit, GLenum TextureTarget, const QString& FileName, bool flip);
    void PrepareCubeMap(GLenum TextureUnit, const QString& BaseFileName, bool flip);

protected:
    void resizeEvent(QResizeEvent *);

private:
    QOpenGLContext *mContext;
    QOpenGLFunctions_4_3_Core *mFuncs;

    QOpenGLShaderProgram *mProgram;

    QTimer mRepaintTimer;
    double currentTimeMs;
    double currentTimeS;
    bool   mUpdateSize;
    float  tPrev, angle, rotSpeed;
    float  mFogDensity;

    GLuint mVAOTeapot, mVAOPlane, mVBO, mIBO;
    GLuint TexId;

    Teapot     *mTeapot;
    QMatrix4x4 ModelMatrixTeapot, ViewMatrix, ProjectionMatrix;

    QVector3D  mProjLookat;
    QMatrix4x4 mProjectorMatrix;

    //debug
    void printMatrix(const QMatrix4x4& mat);
};
