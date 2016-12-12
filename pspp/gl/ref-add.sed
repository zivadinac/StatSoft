/^# Packages using this file: / {
  s/# Packages using this file://
  ta
  :a
  s/ pspp / pspp /
  tb
  s/ $/ pspp /
  :b
  s/^/# Packages using this file:/
}
