public class Test0 {
    public static void main(String[] args) {
        System.out.println("Hello, World from Java!");
        GgmlGlobal.test();
        GgmlContext ctx = GgmlGlobal.initContext(128*1024*1024);
        GgmlTensor tensor1 = GgmlGlobal.newTensor1d(ctx, GgmlType.F32.getValue(), 10);
        GgmlTensor tensor2 = GgmlGlobal.newTensor2d(ctx, GgmlType.I16.getValue(), 10, 20);
        GgmlTensor tensor3 = GgmlGlobal.newTensor3d(ctx, GgmlType.I32.getValue(), 10, 20, 30);
        System.out.println(tensor1);
        assert tensor1.getNe()[0] == 10;
        System.out.println(tensor2);
        assert tensor2.getNe()[0] == 10;
        assert tensor2.getNe()[1] == 20;
        System.out.println(tensor3);
        assert tensor3.getNe()[0] == 10;
        assert tensor3.getNe()[1] == 20;
        assert tensor3.getNe()[2] == 30;

    }
}
