import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class cspppp {
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Character> uniqueChars = new ArrayList<>();
    static HashMap<Character, Integer> charToDigitMap = new HashMap<>();
    static String s1, s2, s3;
    static boolean solutionFound = false;

    public static void main(String[] args) {
        System.out.println("Enter string 1:");
        s1 = sc.nextLine().toUpperCase();
        System.out.println("Enter string 2:");
        s2 = sc.nextLine().toUpperCase();
        System.out.println("Enter string 3:");
        s3 = sc.nextLine().toUpperCase();

        addUniqueCharacters(s1);
        addUniqueCharacters(s2);
        addUniqueCharacters(s3);
        
        calculate();
    }

    public static void addUniqueCharacters(String s) {
        for (char c : s.toCharArray()) {
            if (!uniqueChars.contains(c)) {
                uniqueChars.add(c);
            }
        }
    }

    public static void calculate() {
        if (uniqueChars.size() > 10) {
            System.out.println("No solution exists! More than 10 unique characters.");
            return;
        }

        int[] digits = new int[uniqueChars.size()];
        boolean[] used = new boolean[10];
        backtrack(digits, used, 0);

        if (!solutionFound) {
            System.out.println("No solution found!");
        }
    }
    
    public static void backtrack(int[] digits, boolean[] used, int index) {
        if (index == uniqueChars.size()) {
            for (int i = 0; i < uniqueChars.size(); i++) {
                charToDigitMap.put(uniqueChars.get(i), digits[i]);
            }

            if (charToDigitMap.get(s1.charAt(0)) == 0 ||
                charToDigitMap.get(s2.charAt(0)) == 0 ||
                charToDigitMap.get(s3.charAt(0)) == 0) {
                return;
            }

            long num1 = getNumber(s1);
            long num2 = getNumber(s2);
            long num3 = getNumber(s3);

            if (num1 + num2 == num3) {
                solutionFound = true;
                System.out.println("Solution found:");
                System.out.println(s1 + " + " + s2 + " = " + s3);
                System.out.println(num1 + " + " + num2 + " = " + num3);
                System.exit(0); 
            }
            return;
        }

        for (int digit = 0; digit < 10; digit++) {
            if (!used[digit]) {
                digits[index] = digit;
                used[digit] = true;
                backtrack(digits, used, index + 1);
                used[digit] = false; 
            }
        }
    }

    public static long getNumber(String s) {
        long number = 0;
        for (char c : s.toCharArray()) {
            number = number * 10 + charToDigitMap.get(c);
        }
        return number;
    }
}
