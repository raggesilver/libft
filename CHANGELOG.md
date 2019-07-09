# Changelog

## Unreleased - 2019-07-09

### Deprecated
- All `t_file` functions were changed, this means no compatibility with any previous version. Essentially **`t_file` functions do not malloc anymore**, they all return a copy of `t_file`
