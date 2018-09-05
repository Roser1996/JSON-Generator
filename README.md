## Simple JSON Generator
### Introduction
**This is a simple and efficient JSON generator written in C++. The APIs are easy to use.**

### Demo
Try the test.cpp
```
$make
$./test
```

**The JSON text will be like**
```
[ 
  { "name": "Roser", "age": 22 },
  { 
    "skills": "C++",
    "skills": "Python",
    "skills": "Swift",
    "skills": "objective C",
    "website": "www.github.com",
    "path": [ 
      "back end",
      "algorithm",
      "ios",
      "linux"
    ],
    "short-array": [ 1, 188900967593046, 3.14159 ]
  },
  false
]
```

If you want to compress the JSON text, you need to call *ConfigureCompressOutput()* in the very beginning.
**The JSON text will be like**
```
[{"name":"Roser","age":22},{"skills":"C++","skills":"Python","skills":"Swift","skills":"objective C","website":"www.github.com","path":["back end","algorithm","ios","linux"],"short-array":[1,188900967593046,3.14159]},false]
```

### Save to file
If you want to save the JSON text to the file, try the following
```
$./test > 1.txt
```




