# 10-排序4 统计工龄 （20 分）

时间限制: 400 ms

内存限制: 64 MB

代码长度限制: 16 KB

给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

## 输入格式

输入首先给出正整数N（≤10​5​​），即员工总人数；随后给出N个整数，即每个员工的工龄，范围在[0, 50]。

## 输出格式

按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

## 输入样例

```bash
8
10 2 0 5 7 2 5 2
```

## 输出样例

```bash
0:1
2:3
5:2
7:1
10:1
```

## 提交结果

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample 有人数为0的段|答案正确|2 ms|512KB|
|1|最大N，工龄全0|答案正确|18 ms|768KB|
|2|最大N，按递减顺序给出|答案正确|19 ms|788KB|