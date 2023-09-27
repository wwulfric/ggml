#include <jni.h>
#include <stdio.h>
#include "NativeDemo.h"
#include "ggml/ggml.h"

JNIEXPORT void JNICALL Java_NativeDemo_printHello(JNIEnv *env, jobject obj) {
    printf("Hello from C!\n");
    struct ggml_init_params params = {
            .mem_size   = 128*1024*1024,
            .mem_buffer = NULL,
            .no_alloc   = false,
    };

    struct ggml_context * ctx0 = ggml_init(params);

    struct ggml_tensor * t1 = ggml_new_tensor_1d(ctx0, GGML_TYPE_F32, 10);
    printf("t1->n_dims: %d\n", t1->n_dims);
}
