import java.util.Scanner;

public class Season{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入月份：");
        //输入月份
		int month = sc.nextInt();
		//判断数字是否为1至12，否则重新输入
        while(month < 1 || month > 12){
            System.out.print("输入有误，请重新输入月份：");
            month = sc.nextInt();
        }

        //判断季节
        if(month<=5 && month>= 3){
            System.out.println("该月份为春季。");
        }else if(month<=8 && month>= 6){
            System.out.println("该月份为夏季。");
        }else if(month<=11 && month>= 9){
            System.out.println("该月份为秋季。");
        }else{
            System.out.println("该月份为冬季。");
        }
    }
}
