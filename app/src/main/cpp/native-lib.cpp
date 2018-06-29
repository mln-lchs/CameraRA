#include <jni.h>
#include <string>
extern "C" {
#include "ubar_seeds.h"
#include "ubar_gradient_std.h"
#include "ubar_ellipse_detector.h"
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_mlanie_camerara_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jfloatArray
JNICALL
Java_com_example_mlanie_camerara_CameraFragment_testUbleam(
        JNIEnv *env,
        jobject callingObject,
        jintArray arr,
        jint sizeX,
        jint sizeY) {

    int d_imx = sizeX;
    int d_imy = sizeY;
    int nb_seed = 0;
    const int SIZE_CHUNK = 2 * 1024;
    /* Allocate memory for the gradient extraction */
    unsigned char *IMAGE = (unsigned char *) malloc(d_imy * d_imx * sizeof(unsigned char));
    unsigned char *ORIENT = (unsigned char *) malloc(d_imy * d_imx * sizeof(unsigned char));
    unsigned char *AMPLITUDE = (unsigned char *) malloc(d_imy * d_imx * sizeof(unsigned char));
    /* Allocate memory for the seed extraction */
    int *SEED_I = (int *) malloc(d_imy * d_imx * sizeof(int));
    int *SEED_J = (int *) malloc(d_imy * d_imx * sizeof(int));
    int *SEED_NEGATIVE = (int *) malloc(d_imy * d_imx * sizeof(int));
    int *N_SEEDS = (int *) malloc(sizeof(int));
    /* Allocate memory for the ellipse detection */
    float *ELLIPSES = (float *) malloc(512 * SIZE_CHUNK * sizeof(float));
    int *CHUNK_I = (int *) malloc(512 * SIZE_CHUNK * sizeof(int));
    int *CHUNK_J = (int *) malloc(512 * SIZE_CHUNK * sizeof(int));
    int *N_CHUNK = (int *) malloc(512 * sizeof(int));
    int *N_ELLIPSE = (int *) malloc(sizeof(int));

    /* Cast the byte from Java into jByteArray */
    //jbyteArray *bArray = reinterpret_cast<jbyteArray *>(&byteArrayObj);
    //jsize len = env->GetArrayLength(*bArray);
    //u_char *data_img = (u_char *) env->GetByteArrayElements(*bArray, 0);

    /* Copy Image Data
    int len = env->GetArrayLength(arr);
    int * data_img = (int *) malloc(len * sizeof(int));
    memcpy(data_img, arr, len * sizeof(int));*/

    //char buf[64];
    //sprintf(buf, "%d %d", IMAGE[0], data_img[5]);

    u_char *data_img = (u_char *) env->GetIntArrayElements(arr,0);
    int i, j;
    for (i = 0; i < d_imx; i++) {
        for (j = 0; j < d_imy; j++) {
            IMAGE[i*d_imy+j] = (unsigned char) (0.299*data_img[4*(j*d_imx+i)+2]+0.587*data_img[4*(j*d_imx+i)+1]+0.114*data_img[4*(j*d_imx+i)]);
        }
    }

    /* Call the gradient extraction */

    ubar_ampl_orient_sobel_std(
            IMAGE,
            d_imy,
            d_imx,
            AMPLITUDE,
            ORIENT);

    /*for (i = 0; i < d_imx; i++) {
        for (j = 0; j < d_imy; j++) {
            data_img[4*(j*d_imx+i)] = AMPLITUDE[i*d_imy+j];
            data_img[4*(j*d_imx+i)+1] = AMPLITUDE[i*d_imy+j];
            data_img[4*(j*d_imx+i)+2] = AMPLITUDE[i*d_imy+j];
            data_img[4*(j*d_imx+i)+3] = 255;
        }
    }*/


    env->ReleaseIntArrayElements(arr, (jint *) data_img, 0);

    /* Copy of image's gradient
    jintArray imGrad = env->NewIntArray(d_imx*d_imy);
    u_char *p = (u_char *) env->GetIntArrayElements(imGrad,0);

    for (i = 0; i < d_imx; i++) {
        for (j = 0; j < d_imy; j++) {
            p[4*(j * d_imx + i)] = AMPLITUDE[i*d_imy +j];;
            p[4*(j * d_imx + i)+1] = AMPLITUDE[i*d_imy +j];
            p[4*(j * d_imx + i)+2] = AMPLITUDE[i*d_imy +j];
            p[4*(j * d_imx + i)+3] = 255;
        }
    }
    env->ReleaseIntArrayElements(imGrad, (jint*) p, 0);*/

    /* Call seed extraction */
    ubar_seeds(
            ORIENT,
            AMPLITUDE,
            d_imy,
            d_imx,
            1,  // use_cross_viewfinder
            SEED_I,
            SEED_J,
            SEED_NEGATIVE,
            N_SEEDS);

    nb_seed = *N_SEEDS;

    /* Call ellipse detection */
    ubar_ellipse_detector_detailed(
            ORIENT, // [in] Gradient orientation numbers between 0 and 7 (>7 means no gradient)
            AMPLITUDE,   // [in] Gradient amplitude
            d_imy,
            d_imx,
            SEED_I,
            SEED_J,
            SEED_NEGATIVE,
            nb_seed,
            ELLIPSES,
            CHUNK_I,
            CHUNK_J,
            N_CHUNK,
            N_ELLIPSE);


    /* Display chunks and seeds */
    int cpt = 0;
    for (i=0 ; i<*N_ELLIPSE ; i++) {
        for (j=0 ; j<N_CHUNK[i] ; j++) {
            data_img[4*(CHUNK_J[cpt+j] * d_imx + CHUNK_I[cpt+j])] = 0;
            data_img[4*(CHUNK_J[cpt+j] * d_imx + CHUNK_I[cpt+j])+1] = 0;
            data_img[4*(CHUNK_J[cpt+j] * d_imx + CHUNK_I[cpt+j])+2] = 255;
            data_img[4*(CHUNK_J[cpt+j] * d_imx + CHUNK_I[cpt+j])+3] = 255;
        }
        cpt += N_CHUNK[i];
    }

    for (i=0; i<*N_SEEDS; i++) {
        data_img[4*(SEED_J[i] * d_imx + SEED_I[i])] = 255;
        data_img[4*(SEED_J[i] * d_imx + SEED_I[i])+1] = 255;
        data_img[4*(SEED_J[i] * d_imx + SEED_I[i])+2] = 0;
        data_img[4*(SEED_J[i] * d_imx + SEED_I[i])+3] = 255;
    }

    env->ReleaseIntArrayElements(arr, (jint *) data_img, 0);

    /* Get the first ellipse and display its value */
    char buf[200];
    sprintf(buf, "Nb seed : %d. Nb ellipses = %d \n x = %f, y = %f, a = %f, b = %f, theta = %f", *N_SEEDS, *N_ELLIPSE, ELLIPSES[1], ELLIPSES[0], ELLIPSES[2], ELLIPSES[3], ELLIPSES[4]);

    jfloatArray res = env->NewFloatArray(5);
    if (*N_ELLIPSE>0) {
        env->SetFloatArrayRegion(res,0,5,ELLIPSES);
    } else {
        float *zeros = (float *) malloc(5*sizeof(float));
        zeros[0] = 0;
        zeros[1] = 0;
        zeros[2] = 0;
        zeros[3] = 0;
        zeros[4] = 0;
        env->SetFloatArrayRegion(res,0,5,zeros);
        free(zeros);
    }


    /* Free memory */
    free(IMAGE);
    free(ORIENT);
    free(AMPLITUDE);
    free(SEED_NEGATIVE);
    free(SEED_I);
    free(SEED_J);
    free(N_SEEDS);
    free(ELLIPSES);
    free(CHUNK_I);
    free(CHUNK_J);
    free(N_CHUNK);
    free(N_ELLIPSE);

    return res;
}
