# 에러 별 대처 모음

<br>

<br>

<br>

## Queue가 비어있는데 참조를 시도할 때

```
Expression: deque iterator not dereferencable
```

대처요령:

1. queue가 있는 로직을 살펴본다.
2. 비어있는데 참조연산을 할 가능성을 따져본다.