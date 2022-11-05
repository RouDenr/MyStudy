#!/bin/bash
echo '----------------------'
echo 'Size    Used    Avail'
echo '----------------------'
df -h | grep Users | awk '{print $2 " = " $3 " + "  $4}'
#df -h | awk 'NR == 8{print $2 " = " $3 " + "  $4}'
#df -h | created/by/mmargene\Support/Peer/sh
rm -rf ~/Library/Application\ Support/Code/Cache/Cache_Data/* -y
rm -rf ~/Library/Application\ Support/Slack/Cache/* -y
rm -rf ~/Library/Application\ Support/Slack/IndexedDB/https_app.slack.com_0.indexeddb.blob/1/* -y
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage/* -y
rm -rf ~/Library/Application\ Support/Google/Chrome/Default/Service\ Worker/CacheStorage/*
rm -rf ~/Library/Application\ Support/Google/Chrome/Crashpad/completed/*
rm -rf ~/Library/Caches/* -y
rm -rf ~/.Trash/* -y
rm -rf ~/Library/Safari/* -y
rm -rf ~/.kube/cache/* -y
rm -rf ~/Library/Application\ Support/Code/CachedData/* -y
rm -rf ~/Library/Application\ Support/Code/Crashpad/completed/* -y
rm -rf ~/Library/Application\ Support/Code/User/workspaceStoratge/* -y
rm -rf ~/Library/Containers/com.docker.docker/Data/vms/* -y
rm -rf ~/Library/Containers/com.apple.Safari/Data/Library/Caches/* -y
#rm -rf ~/Library/Containers/org.telegram.desktop/Data/Library/Application\ Support/Telegram\ Desktop/tdata/emoji/* -y
df -h | grep Users | awk '{print $2 " = " $3 " + "  $4}'
#df -h | awk 'NR == 8{print $2 " = " $3 " + "  $4}'
echo '----------------------'
