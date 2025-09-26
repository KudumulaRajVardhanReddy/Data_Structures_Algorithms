#include <bits/stdc++.h>
using namespace std;

void extract_num(int num) {
    while (num > 0) {
        cout << num%10 << endl;
        num /= 10;
    }
    
}

int count_digs_of_num(int num) {
    return ((int)(log10(num)+1));
}

int rev_num(int num) {
    int reversed_num{0};
    while(num > 0) {
        reversed_num = reversed_num*10 + (num%10);
        num /= 10;
    }
    return reversed_num;
}

bool check4palindrome(int num) {
    int original{num}, reversed_num{0};

    while (num > 0) {
        reversed_num = reversed_num*10 + (num%10);
        num /= 10;
    }
    return (original == reversed_num);
}

bool armstrongNumChecker(int num) {
    int tampered{num}, armstrong_create{0}, counter{0};

    while(tampered > 0) {
        counter += 1;
        tampered /= 10;
    }

    tampered = num;

    while(tampered > 0) {
        armstrong_create += pow(tampered%10, counter);
        tampered /= 10;
    }
    return (armstrong_create == num);
}

void print_divisors(int num){
    for (int i{1}; i <= num; i++) {
        if (num%i==0) cout << i << endl; 
    }    
}

void print_divisors_efficiently(int num) {
    vector<int> divisors;

    for(int i{1}; i*i <= num; i++) {
        if (num%i==0) {
            divisors.push_back(i);
            divisors.push_back(num/i);
            
            if (num/i == i) divisors.push_back(i);
        }
    }

    sort(divisors.begin(), divisors.end());
    for (auto it: divisors) cout << it << endl;
}

bool prime_checker(int num) {
    int count{0};
    for(int i{1}; i*i <= num; i++) {
        if (num%i == 0) {
            count++;
            if(num/i!=i) count++;
        }
    }
    if (count == 2) return true;
    return false;
}

int gcd(int num1, int num2) {
    int gcd{1};
    for (int i{min(num1, num2)}; i >= 1; i--) {
        if (num1%i==0 && num2%i ==0) {
            gcd = i;
            break;
        }
    } 
    return gcd;
}

int rec_gcd(int num1, int num2) {
    if (num1 == 0) return num2;
    else if (num2 == 0) return num1;
    else if (num1 > num2) return rec_gcd(num1 % num2, num2);
    else return rec_gcd(num2 % num1, num1);
} 

int rec_gcd_tb(int num1, int num2) {
    if (num2 == 0) return num1;
    return rec_gcd(num2, num1 % num2);
}

void print_names_n_times(int num, string name) {
    if(num>0) {
        cout << name << endl;
        print_names_n_times(num-1, name);
    } else return;
}

void print_upto_n_recursion(int num, int begin) {
    if (begin <= num) {
        cout << begin << endl;
        begin++;
        print_upto_n_recursion(num, begin);
    } else return;
}

void print_upto_nInRev_recursion(int num) {
    if (num > 0) {
        cout << num << endl;
        print_upto_nInRev_recursion(num-1);
    }
}

int sum_n_recursion(int num) {
    if(num == 0) {
        return 0;
    } else return num + sum_n_recursion(num-1);
}

int recursive_factorial(int num) {
    if (num == 1) return 1;
    else return num*recursive_factorial(num-1);
}

void recursive_revArray(int arr[], int arr_size) {
    if (arr_size == 0) return;
    cout << arr[arr_size - 1] << endl;
    recursive_revArray(arr, arr_size-1);
}

int recursive_fibo_sum(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    return recursive_fibo_sum(num-1) + recursive_fibo_sum(num-2);
}

void print_fibo(int num, int current = 0) {
    if (current > num) return;
    cout << recursive_fibo_sum(current) << endl;
    print_fibo(num, current + 1);
}

bool palindrome_checker_for_string(int index, string &str) {
    if (index >= str.size() / 2) return true;
    if (str[index] != str[str.size() - index - 1]) return false;
    return palindrome_checker_for_string(index+1, str);
}

int main() {
    extract_num(2686312);
    cout << endl;
    cout << count_digs_of_num(2686312) << endl;
    cout << endl;
    cout << rev_num(2342745) << endl;
    cout << endl;
    cout << boolalpha << check4palindrome(121) << endl;
    cout << endl;
    cout << boolalpha << armstrongNumChecker(1634) << endl;
    cout << endl;
    print_divisors(36);
    cout << endl;
    print_divisors_efficiently(36);
    cout << endl;
    cout << boolalpha << prime_checker(17) << endl;
    cout << endl;
    cout << gcd(12, 3) << endl;
    cout << endl;
    cout << rec_gcd(289, 17) << endl;
    cout << endl;
    print_names_n_times(5, "Raj");
    cout << endl;
    print_upto_n_recursion(5, 1);
    cout << endl;
    print_upto_nInRev_recursion(5);
    cout << endl;
    cout << sum_n_recursion(241) << endl;
    cout << endl;
    cout << recursive_factorial(5) << endl;
    cout << endl;
    int arr[] = {1,2,3,4,5};
    recursive_revArray(arr, 5);
    cout << endl;
    cout << recursive_fibo_sum(8) << endl;
    cout << endl;
    print_fibo(5);
    cout << endl;
    string name = "Madam";
    cout << boolalpha << palindrome_checker_for_string(0, name) << endl;

    return 0;
}
