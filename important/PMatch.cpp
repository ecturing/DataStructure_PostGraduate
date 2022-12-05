/**
 * @file PMatch.cpp
 * @author ecturing (you@domain.com)
 * @brief 括号匹配
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>

using namespace std;

void Pmatching() {
  map<char, char> keymap; //括号对应映射
  keymap[']'] = '[';
  keymap[')'] = '(';
  keymap['}'] = '{';

  stack<char> stack; //运算栈

  char input;
  printf("input now(输入括号序列后把N作为输入完成标识符):");
  while (true) {
    scanf("%c", &input);
    if (input == '[' || input == '(' || input == '{') {
      stack.push(input);
    } else if (input == ']' || input == ')' || input == '}') {
      if (!stack.empty()) {//防止如()}的情况出现，必须校验是否为空
        /* code */
        char top = stack.top();
        if (top == keymap[input]) {
          stack.pop();
        }
      } else {
        stack.push(input);//若栈为空则直接压入
      }
    } else if (input == 'N') {//结束标识符
      break;
    }
  }
  if (stack.empty()) {//通过运算栈的是否为空校验是否完成匹配
    printf("the input is ture\n");
  } else {
    printf("the input is false");
  }
}

int main() { Pmatching(); }