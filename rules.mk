### Some potentially needed stuff taken from
### https://github.com/GEIGEIGEIST/qmk-config-totem/blob/main/totem/rules.mk
# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS = yes

#SPACE SAVING
AUDIO_ENABLE = no
MUSIC_ENABLE = no
# LTO must be disabled for RP2040 builds
LTO_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
