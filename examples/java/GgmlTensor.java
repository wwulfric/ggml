public class GgmlTensor {
    private int type;
    private int dims;
    private long[] ne;
    private long[] nb;

    public GgmlTensor(int type, int dims, long[] ne, long[] nb) {
        this.type = type;
        this.dims = dims;
        this.ne = ne;
        this.nb = nb;
    }

    public int getType() {
        return this.type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public int getDims() {
        return this.dims;
    }

    public void setDims(int dims) {
        this.dims = dims;
    }

    public long[] getNe() {
        return this.ne;
    }

    public void setNe(long[] ne) {
        this.ne = ne;
    }

    public long[] getNb() {
        return this.nb;
    }

    public void setNb(long[] nb) {
        this.nb = nb;
    }



    @Override
    public String toString() {
        return "{" +
            " type='" + getType() + "'" +
            ", dims='" + getDims() + "'" +
            ", ne='" + toString(getNe()) + "'" +
            ", nb='" + toString(getNb()) + "'" +
            "}";
    }

    private String toString(long[] arr) {
        String str = "[";
        for (int i = 0; i < arr.length; i++) {
            str += arr[i];
            if (i < arr.length - 1) {
                str += ", ";
            }
        }
        str += "]";
        return str;
    }

}
