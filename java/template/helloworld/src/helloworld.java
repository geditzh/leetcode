public class helloworld {
    public static int max(int a, int b)
    {
        int temp;
        temp = a > b ? a : b;
        return temp;
    }

    public int min(int a, int b)
    {
        int temp;
        return temp = a > b ? b : a;
    }

    public static void main(String[] args)
    {
        int a = 100;
        int b = 200;
        int res = max(a, b);

        helloworld hw = new helloworld();

        int res2 = hw.min(a, b);
        System.out.println(res2);

        System.out.println(res);
        System.out.println("zhanghan");
    }
}
