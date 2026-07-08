#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

cmake --build "${script_dir}" --target exe

if [[ $# -eq 0 ]]; then
    echo "${script_dir}/bin/exe"
    "${script_dir}/bin/exe"
else
    echo "${script_dir}/bin/exe ${1}"
    "${script_dir}/bin/exe" "${1}"
fi
