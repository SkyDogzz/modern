#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

cmake --build "${script_dir}" --target exe
"${script_dir}/bin/exe"
