#!/bin/bash

SRC_DIR="../src"
DEST_DIR="../includes"

echo "[INFO] Copying header files from $SRC_DIR to $DEST_DIR..."

if [ ! -d "$DEST_DIR" ]; 
  then
    echo "[WARN] Destination directory $DEST_DIR does not exist."
    echo "[INFO] Creating destination directory $DEST_DIR..."
    mkdir -p "$DEST_DIR"
fi

find "$SRC_DIR" -type f -name "*.h" -print0 |
    while IFS= read -r -d '' file_path; do
  relative_path="${file_path#$SRC_DIR/}"
  dest_file_path="$DEST_DIR/$relative_path"
  dest_dir_path=$(dirname "$dest_file_path")

  if [ ! -d "$dest_dir_path" ]; then
    echo "[WARN] Destination subdirectory $dest_dir_path does not exist."
    echo "[INFO] Creating destination subdirectory $dest_dir_path..."
    mkdir -p "$dest_dir_path"
  fi
    
  cp -p "$file_path" "$dest_file_path"
  echo "[ OK ] Copied: $file_path -> $dest_file_path"
done

echo "[ OK ] All header files are copied successfully."
