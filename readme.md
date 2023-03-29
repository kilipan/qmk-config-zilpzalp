# zilpzalp

![zilpzalp]()

*A wonky 28-key split-unibody column-stagger keyboard.*  
**IMPORTANT: This firmware is only suitable for the Seeed Xiao RP2040 MCU!**
If you would like to use a different MCU, please consider using ZMK firmware.

* Keyboard Maintainer: [kilipan](https://github.com/kilipan)
* Hardware Supported: *zilpzalp keyboard with Seeed Studio Xiao RP2040 Controller*
* Hardware Availability: [*production files*](https://github.com/kilipan/zilpzalp)

Make example for this keyboard (after setting up your build environment):

    make zilpzalp:default

Flashing example for this keyboard:

    make zilpzalp:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Default keymap
The default keymap is set to QWERTY with the `Q`, `Z`, `B`, `N`, `/`, and `P` keys missing. They are reacheable via combos.
Please consult the [keymap file](https://github.com/kilipan/zilpzalp_qmk/keymaps/default/keymap.c) for further details.

## Bootloader

Enter the bootloader in 3 ways:

* **Physical reset button**: Press the reset button (labelled "R") while holding down the bootloader button (labelled "B")
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (hold right button of the right thumb and press the top button of the left ring finger
