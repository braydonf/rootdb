RootDB
======

## Objective

Store key/value pair data to disk that can be distributed and cryptographically verified for byte-for-byte integrity. A root hash that represents the entire data set should be efficiently calculated without needing to serialize and read large amounts of data that can take several minutes. It should also be possible to prove that a portion of the database exists in a whole with comparison to the database's root hash. The performance of both insertion and deletion of keys is critical. The library should be portable into other projects and scripting languages and written in C/C++.

## Build

**Note:** Current development and testing is with Ubuntu 15.10.

Build requirements:

```bash
apt-get install build-essential libtool autotools-dev automake check
```

Library requirements:

```bash
apt-get install liblmdb-dev libssl-dev
```

```bash
./autogen.sh
./configure
make
```

To run tests:
```bash
make check
```

## Related

- Ethereum Merkle Patricia Tree
  - https://github.com/ethereum/wiki/wiki/Patricia-Tree
  - https://easythereentropy.wordpress.com/2014/06/04/understanding-the-ethereum-trie/
  - https://github.com/ethereumjs/merkle-patricia-tree
- Bitcoin Merkle Tree
  - https://en.bitcoin.it/wiki/Protocol_documentation#Merkle_Trees
  - https://en.wikipedia.org/wiki/Merkle_tree
- Tendermint Merkle-ized Data Structures
  - https://github.com/tendermint/go-merkle
- Node Merkle Tree
  - https://github.com/keybase/node-merkle-tree
