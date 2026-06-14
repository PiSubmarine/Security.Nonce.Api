# Security.Nonce.Api

`PiSubmarine.Security.Nonce.Api` defines the minimal contract for nonce values
and stateful nonce allocation.

## Responsibility

This module owns:

- byte-oriented nonce value type
- provider interface for sequential nonce generation
- domain-specific error codes for nonce exhaustion and invalid configuration

It does not own:

- AEAD primitives
- key management
- datagram framing
- lease semantics
