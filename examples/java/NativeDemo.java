public class NativeDemo {
    // 声明一个native方法
    public native void printHello();

    // 加载包含native方法实现的动态链接库
    static {
        System.loadLibrary("Hello");
    }


    public static void main(String[] args) {
        // 调用native方法
        new NativeDemo().printHello();
    }
}