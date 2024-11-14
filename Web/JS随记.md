# String.split()

- ( )中放分割符号- “...............分隔符...............”
- ( )中放正则表达式-“/  正则表达式   /”

```javascript
//空参数
var str = '君不见黄河之水天上来';
var arr = str.split();
console.log(arr) // ["君不见黄河之水天上来"]

//,分割
var str = '君不见,黄河,之水/天上来';
var arr =str.split(',');
console.log(arr) // ["君不见","黄河","之水/天上来"]

//正则表达式分割
var str = '君 & 不见 & 黄河& 之水 &天上来,奔流 & 到海 & 不复回';
var arr = str.split(/\s+&\s+/);
console.log(arr) // ["君","不见","黄河& 之水 &天上来,奔流","到海","不复回"]

```

# isNaN()

is Not a Number()

是 不是 一个 数字

如果括号中是一个数字，则这个函数返回false；

如果括号中不是一个数字，则这个函数返回true；

但是***注意一下以下几点***

```javascript
//括号中不是number类型的会被系统转换成number类型

isNaN('Hello') // true
// 相当于
isNaN(Number('Hello')) // true
 
isNaN({}) // true
// 等同于
isNaN(Number({})) // true
 
isNaN(['xzy']) // true
// 等同于
isNaN(Number(['xzy'])) // true
```

# String 转换成数组-Array.from(Str)

```javascript
var a1 = Array.from(str);
```

# ASCII码转换-charCodeAt()

```javascript
aw1[i].charCodeAt()-'a'.charCodeAt()
```



