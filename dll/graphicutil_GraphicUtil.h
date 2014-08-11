/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class graphicutil_GraphicUtil */

#ifndef _Included_graphicutil_GraphicUtil
#define _Included_graphicutil_GraphicUtil
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     graphicutil_GraphicUtil
 * Method:    clearScreen
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_clearScreen
  (JNIEnv *, jclass);

/*
 * Class:     graphicutil_GraphicUtil
 * Method:    setTextColor
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_setTextColor
  (JNIEnv *, jclass, jint);

/*
 * Class:     graphicutil_GraphicUtil
 * Method:    captureKeyboardArrows
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_graphicutil_GraphicUtil_captureKeyboardArrows
  (JNIEnv *, jclass);

/*
 * Class:     graphicutil_GraphicUtil
 * Method:    setCursorPosition
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_setCursorPosition
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     graphicutil_GraphicUtil
 * Method:    hideCursor
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_hideCursor
  (JNIEnv *, jclass, jboolean);

#ifdef __cplusplus
}
#endif
#endif