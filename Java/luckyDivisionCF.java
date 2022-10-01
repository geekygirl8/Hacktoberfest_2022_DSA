import java.util.*;
public class luckyDivisionCF {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int arr [] = {4,7,47,74,477,447,444,44,77,777,774,744};
        int flag = 0;
        for(int i = 0; i < arr.length; i++){
            if(n % arr[i] == 0)
            flag = 1;
        }
        System.out.print(flag == 1? "YES" : "NO");
    }
}
