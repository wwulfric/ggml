#include <jni.h>
#include <stdio.h>
#include "GgmlGlobal.h"
#include "ggml/ggml.h"

struct ggml_context * convert_from_java(JNIEnv *env, jobject ctx) {
    jclass ggmlContextClazz = (*env)->GetObjectClass(env, ctx);
    jfieldID memSizeFieldId = (*env)->GetFieldID(env, ggmlContextClazz, "memSize", "J");
    jlong memSize = (*env)->GetLongField(env, ctx, memSizeFieldId);
    struct ggml_init_params params = {
            .mem_size   = memSize,
            .mem_buffer = NULL,
            .no_alloc   = false,
    };
    return ggml_init(params);
}

jobject convert_to_java(JNIEnv *env, struct ggml_tensor * t, jobject ctx) {
    jclass clazz = (*env)->FindClass(env, "GgmlTensor");
    jmethodID constructor = (*env)->GetMethodID(env, clazz, "<init>", "(II[J[J)V");
    jlongArray neArray = (*env)->NewLongArray(env, GGML_MAX_DIMS);
    jlongArray nbArray = (*env)->NewLongArray(env, GGML_MAX_DIMS);
    (*env)->SetLongArrayRegion(env, neArray, 0, GGML_MAX_DIMS, (jlong *)t->ne);
    (*env)->SetLongArrayRegion(env, nbArray, 0, GGML_MAX_DIMS, (jlong *)t->nb);
    jobject res = (*env)->NewObject(env, clazz, constructor, t->type, t->n_dims, neArray, nbArray);
    (*env)->DeleteLocalRef(env, neArray);
    (*env)->DeleteLocalRef(env, nbArray);
    return res;
}

JNIEXPORT void JNICALL Java_GgmlGlobal_test
        (JNIEnv *env, jclass clazz) {
    printf("Hello from C!\n");
}

JNIEXPORT jobject JNICALL Java_GgmlGlobal_newTensor1d
        (JNIEnv *env, jclass clazz, jobject ctx, jint type, jlong ne0) {
    struct ggml_context * ctx_in_c = convert_from_java(env, ctx);
    struct ggml_tensor * t1 = ggml_new_tensor_1d(ctx_in_c, type, ne0);
    return convert_to_java(env, t1, ctx);
}


JNIEXPORT jobject JNICALL Java_GgmlGlobal_newTensor2d
        (JNIEnv *env, jclass clazz, jobject ctx, jint type, jlong ne0, jlong ne1) {
    struct ggml_context * ctx_in_c = convert_from_java(env, ctx);
    struct ggml_tensor * t1 = ggml_new_tensor_2d(ctx_in_c, type, ne0, ne1);
    return convert_to_java(env, t1, ctx);
}



JNIEXPORT jobject JNICALL Java_GgmlGlobal_newTensor3d
        (JNIEnv *env, jclass clazz, jobject ctx, jint type, jlong ne0, jlong ne1, jlong ne2) {
    struct ggml_context * ctx_in_c = convert_from_java(env, ctx);
    struct ggml_tensor * t1 = ggml_new_tensor_3d(ctx_in_c, type, ne0, ne1, ne2);
    return convert_to_java(env, t1, ctx);
}
