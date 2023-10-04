public enum GgmlType {
    F32(0),
    F16(1),
    Q4_0(2),
    Q4_1(3),
    I16(17),
    I32(18),

    ;
    private final int value;
    private GgmlType(int value) {
        this.value = value;
    }
    public int getValue() {
        return value;
    }
}
