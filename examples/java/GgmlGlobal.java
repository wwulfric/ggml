public class GgmlGlobal {
    // 加载包含native方法实现的动态链接库
    static {
        System.loadLibrary("GgmlGlobal");
    }
    public static native void test();

    public static GgmlContext initContext(long memSize) {
        GgmlContext ctx = new GgmlContext();
        ctx.setMemBuffer(null);
        ctx.setMemSize(memSize);
        return ctx;
    }
    public static native GgmlTensor newTensor1d(GgmlContext ctx, int type, long ne0);
    public static native GgmlTensor newTensor2d(GgmlContext ctx, int type, long ne0, long ne1);
    public static native GgmlTensor newTensor3d(GgmlContext ctx, int type, long ne0, long ne1, long ne2);
//     public static native void setParam(GgmlContext ctx, GgmlTensor a);
//     public static native GgmlTensor mul(GgmlContext ctx, GgmlTensor a, GgmlTensor b);

}