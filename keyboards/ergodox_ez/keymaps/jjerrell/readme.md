# Jacob Jerrell's Ergodox Ez Layout

The original edition Ergodox EZ with a black case, unlabeled white keycaps, and 3 indicator-style LEDs.

The LEDs are currently used for two  things:

1. If on a default layer, it lights up one indicator each for Shift and Alt. Control and Command/Win share one of the indicators, increasing in brightness if both are held.
2. Tri-state and special layer indication or announcement (_GAME blinks all LEDs for visual confirmation)

## Layouts

### Empty ASCII Layout 

```
.---------------------------------------------. .---------------------------------------------.
|       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
!-------+-----+-----+-----+-----+-------------! !-------+-----+-----+-----+-----+-----+-------!
|       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
!-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
|       |     |     |     |     |     |-------! !-------!     |     |     |     |     |       |
!-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
|       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
'-------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+-------'
|      |     |     |     |     |                             !     |     |     |     |      |
'------------------------------'                             '------------------------------'
                              .---------------. .---------------.
                              |       |       | !       |       |
                      .-------+-------+-------! !-------+-------+-------.
                      !       !       |       | !       |       !       !
                      !       !       !-------! !-------!       !       !
                      |       |       |       | !       |       |       |
                      '-----------------------' '-----------------------'
```

### Empty Wrapper

```c
---------- LEFT HAND -----------   ---------- RIGHT HAND ----------
(                                                                    \
L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                        L55,L56,   R50,R51,                          \
                            L54,   R52,                              \
                    L53,L52,L51,   R55,R54,R53                       \
)
```
