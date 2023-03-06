#!/bin/bash
# Delete and reinstall Homebrew from Github repo
BREW_PATH=$HOME/goinfre/.brew
rm -rf "${BREW_PATH}/"
git clone --depth=1 https://github.com/Homebrew/brew "${BREW_PATH}"

# Create .brewconfig script in home directory
cat <<EOL > "$HOME/.brewconfig.zsh"
# HOMEBREW CONFIG

# Add brew to path
export PATH="\${BREW_PATH}/bin:\$PATH"

# Set Homebrew temporary folders
export HOMEBREW_CACHE=/tmp/\$USER/Homebrew/Caches
export HOMEBREW_TEMP=/tmp/\$USER/Homebrew/Temp

mkdir -p "\$HOMEBREW_CACHE"
mkdir -p "\$HOMEBREW_TEMP"

# If NFS session
# Symlink Locks folder in /tmp
if df -T autofs,nfs "\$HOME" &>/dev/null
then
  HOMEBREW_LOCKS_TARGET=/tmp/\$USER/Homebrew/Locks
  HOMEBREW_LOCKS_FOLDER="\${BREW_PATH}/var/homebrew"

  mkdir -p "\$HOMEBREW_LOCKS_TARGET"
  mkdir -p "\$HOMEBREW_LOCKS_FOLDER"

  # Symlink to Locks target folders
  # If not already a symlink
  if ! [[ -L "\$HOMEBREW_LOCKS_FOLDER" && -d "\$HOMEBREW_LOCKS_FOLDER" ]]
  then
     echo "Creating symlink for Locks folder"
     rm -rf "\$HOMEBREW_LOCKS_FOLDER/"
     ln -s "\$HOMEBREW_LOCKS_TARGET" "\$HOMEBREW_LOCKS_FOLDER"
  fi
fi
EOL

# Add .brewconfig sourcing in your .zshrc if not already present
if ! grep -sq "# Load Homebrew config script" "$HOME/.zshrc"
then
  echo '# Load Homebrew config script' >> "$HOME/.zshrc"
  echo '. $HOME/.brewconfig.zsh' >> "$HOME/.zshrc"
fi

. "$HOME/.brewconfig.zsh"
rehash
brew update

echo -e "\nPlease open a new shell to finish installation"
