package main

import "fmt"

func main() {

	n := 6
	l := "111001"

	res := shutdownLight(n, l)
	fmt.Println(res)
}

/*

这是执行结果

编号: 6 的灯是打开状态，开始熄灭该灯以及编号是其因数的灯。。。
编号：5 的灯是熄灭状态，跳过。。。
编号：4 的灯是熄灭状态，跳过。。。
编号：3 的灯是熄灭状态，跳过。。。
编号：2 的灯是熄灭状态，跳过。。。
编号：1 的灯是熄灭状态，跳过。。。
1

 */


// shutdownLight 接受 灯的数量num,l 灯的状态
func shutdownLight(num int, l string) int {

	lArry := make([]string, num)

	for index, status := range l {
		lArry[index] = string(status)
	}

	optionNum := 0

	for i := num; i > 0; i-- {

		lightStatus := lArry[i-1]

		if lightStatus == "0" {
			fmt.Printf("编号：%d 的灯是熄灭状态，跳过。。。\n", i)
			continue
		}

		fmt.Printf("编号: %d 的灯是打开状态，开始熄灭该灯以及编号是其因数的灯。。。\n", i)

		shutdownOtherLight(num, lArry)

		optionNum ++
	}



	return optionNum
}


// shutdownOtherLight 关闭编号是n因数的灯
func shutdownOtherLight(n int, l []string) {
	for j := n-1; j > 0; j-- {
		isFactor := isNumFactor(j, n)
		if !isFactor {
			continue
		}

		// 如果灯的编号是n的因数,那么就熄灭这个灯
		l[j-1] = "0"

	}

}

// isNumFactor 判断factorNum是否是n的因数
func isNumFactor(factorNum, n int) bool {

	if n % factorNum == 0 {
		return true
	}

	return false
}