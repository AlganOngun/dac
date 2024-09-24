## A user friendly, header only dynamic array library

**dac** *(Dynamic Array C)* is a header only dynamic array library. The main point of this library which makes it different is that it is type safe *(no casts)* and still ***intuitive*** to use. an example would be like:

```c
int *da = NULL;

dac_push(da, 50);
dac_push(da, 57);
dac_push(da, 24);
dac_push(da, 64);

for (size_t i = 0; i < dac_len(da); ++i) {
    printf("da[%d] is %d", i, da[i]);
}

dac_free(da);
```

There is currently limited array operations, I will add more as I need them.
