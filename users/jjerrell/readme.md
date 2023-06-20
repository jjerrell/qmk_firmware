# Jacob Jerrell's Userspace

Contains shared firmware implementations for re-use across multiple boards. Additionally, it provides an API for keyboard specific customizations where the `*_user` method is already in use and/or needs to provide additional state information.

## RGB Notes

### For split board layer state indication

If necessary, in config.h:

```h
#define SPLIT_LAYER_STATE_ENABLE
```

### Identifying related light clusters

In a header file:

```h
const uint8_t LED_LIST_ARROWS[] = {
    2,
    13,
    14,
    15
};
```

In an RGB_MATRIX implementation:

```c
for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_ARROWS); i++) {
    rgb_matrix_set_color(LED_LIST_ARROWS[i], RGB_BLUE);
}
```
