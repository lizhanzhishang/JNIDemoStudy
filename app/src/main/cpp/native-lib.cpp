#include <jni.h>
#include <string>
//#include <version>
//#include <version>
//#include <utility>
//#include <chrono>
#include "Logger.h"
using namespace std;

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_analysis_jnidemostudy_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//
//
//    auto p = std::make_pair(1, "C++ 11");
//    auto t1 = make_tuple(1, 2.0, "C++ 11");
////    auto t2 = make_tuple(1, 2.0, "C++ 11", {1, 0, 2});
//
//    int arr[3] = {1, 2, 3};
//
//
//    auto lambda = [](auto x, auto y) {return x + y;};
//    using namespace std::chrono_literals;
//    auto halfmin = 30s;
//
//    auto abc= lambda(1,3);
//    hello=hello+p.second +to_string( (1min + 1s).count());
//
//
//    return env->NewStringUTF(hello.c_str());
//}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
    LOGE("Jni_OnLoad");
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved){
    LOGE("JNI_OnUnload");
}




extern "C" JNIEXPORT jstring JNICALL Java_com_analysis_jnidemostudy_MainActivity_stringFromJNITest
(JNIEnv *env, jobject thiz,jobjectArray array) {
    jint count=env->GetArrayLength(array);
    LOGE(" array count:  %d" ,count);
    for (int i = 0; i < count; ++i) {
        jobject jobject1=env->GetObjectArrayElement(array, i);
        if(jobject1!= NULL){
            const char *path = env->GetStringUTFChars((jstring)jobject1, 0);
            if(path!= NULL){
                LOGE("----------char--->> : %s" ,path);
            } else{
                LOGE("----------char--->> : NUll chars");
            }
        } else{
            LOGE("------------->> : NUll string");
        }
    }
    std::string hello = "Hello from C++ ";
//    hello+=to_string(count);

    return env->NewStringUTF(hello.c_str());

}
extern "C" JNIEXPORT jstring JNICALL
Java_com_analysis_jnidemostudy_MainActivity_stringFromJNIListTest(JNIEnv *env, jobject thiz,
                                                                  jobject array) {

}
extern "C" JNIEXPORT void JNICALL Java_com_analysis_jnidemostudy_MainActivity_sendString(JNIEnv *env, jobject thiz, jstring info,jobject user) {
    const char *path = env->GetStringUTFChars(info, 0);
    if(path!= NULL){
        LOGE("sendString %s" ,path);
    }
    jclass  jclass1=env->FindClass("com/analysis/jnidemostudy/UserInfo");
    jmethodID methodID = env->GetMethodID(jclass1, "sendName", "()V");
    jobject  jobject1=env->AllocObject(jclass1);
    env->CallVoidMethod(jobject1,methodID);

    jclass clsuser = env->GetObjectClass(user);
    jfieldID jfieldIdName=env->GetFieldID(clsuser,"name", "Ljava/lang/String;");
    jfieldID jfieldIdAge=env->GetFieldID(clsuser,"age","I");
    jint ageUser=env->GetIntField(user,jfieldIdAge);
    jstring nameUser=(jstring)env->GetObjectField(user,jfieldIdName);
    const char *nameUChar = env->GetStringUTFChars(nameUser, 0);


    LOGE("sendString %d  %s" ,ageUser, nameUChar);

//    jobject obj, jfieldID fieldID, jint value
    env->SetIntField(user,jfieldIdAge,5676868);
    jint ageUserX=env->GetIntField(user,jfieldIdAge);
    LOGE("sendString %d  %s" ,ageUserX, nameUChar);







}extern "C"
JNIEXPORT jobject JNICALL
Java_com_analysis_jnidemostudy_MainActivity_getOnffice
(JNIEnv *env, jobject thiz, jint a,jstring b) {
    jclass  jclass1=env->FindClass("com/analysis/jnidemostudy/UserInfo");
    jobject  jobject1=env->AllocObject(jclass1);

    jfieldID jfieldIdName=env->GetFieldID(jclass1,"name", "Ljava/lang/String;");
    jfieldID jfieldIdAge=env->GetFieldID(jclass1,"age","I");


    env->SetIntField(jobject1,jfieldIdAge,a);
    env->SetObjectField(jobject1,jfieldIdName,b);
    return jobject1;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_analysis_jnidemostudy_MainActivity_goByte(JNIEnv *env, jobject thiz, jbyteArray array) {
   jsize _num_bytes = env->GetArrayLength(array);
   jbyte* _data = static_cast<jbyte *>(malloc(_num_bytes));
   env->GetByteArrayRegion(array, 0, (jsize)_num_bytes, (jbyte *)_data);

    return env->NewStringUTF(reinterpret_cast<const char *>(_data));
}