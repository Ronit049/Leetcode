🧠 Generative AI Fundamentals — Best Notes

📌 1. Big Picture

For an AI chatbot that answers questions from your own PDFs, documents, websites, or company data:

YOUR DOCUMENTS
      ↓
     RAG
      ↓
Relevant Information
      ↓
  LangChain
      ↓
     LLM
      ↓
    ANSWER

Docker can run and isolate the application's services in containers. fileciteturn0file0L11-L34

🤖 2. LangChain

Definition

LangChain is a framework/library for building applications powered by Large Language Models (LLMs). fileciteturn0file0L42-L44

Real AI applications may need:

User Question
      ↓
Get Question
      ↓
Search Documents
      ↓
Find Relevant Information
      ↓
Send Information + Question to LLM
      ↓
Generate Answer
      ↓
Return Answer

LangChain provides components that help build this type of pipeline. fileciteturn0file0L57-L78

LangChain as a Connector

LLM
 │
 ├── Prompts
 ├── Documents
 ├── Vector Database
 ├── Tools
 ├── APIs
 ├── Memory
 └── Agents

fileciteturn0file0L80-L103

Important

GPT / Claude / Gemini
          ↑
         LLM
          ↑
      LangChain
          ↑
    Your Application

LangChain ≠ GPT. LangChain helps build and orchestrate applications around LLMs; it is not the LLM itself. fileciteturn0file0L119-L135

📚 3. RAG

Full Form

RAG = Retrieval-Augmented Generation

RAG is an architecture for retrieving relevant external information and using it as context for an LLM. fileciteturn0file0L140-L156

Without RAG

User
 ↓
LLM
 ↓
Answer

With RAG

Your PDF
   ↓
Split into Chunks
   ↓
Embeddings
   ↓
Vector Database
   ↑
   │
User Question
   ↓
Retrieval
   ↓
Relevant Chunks
   ↓
LLM
   ↓
Answer

fileciteturn0file0L180-L210

Why the name RAG?

Retrieval

Find relevant information.

Question
   ↓
Search Database
   ↓
Relevant Paragraph

Augmentation

Add the retrieved information to the prompt/context.

Context:
Customers can request a refund within 30 days.

Question:
What is the refund policy?

Generation

The LLM generates the final answer using the question and retrieved context.

Retrieval
    +
Augmentation
    +
Generation
    =
RAG

fileciteturn0file0L217-L281

🗄️ 4. Qdrant

Qdrant is a vector database.

RAG systems can use it to store and search document embeddings. fileciteturn0file0L288-L305

Document flow

PDF
 ↓
Split into Chunks
 ↓
Embedding Model
 ↓
Vectors
 ↓
Qdrant

Question flow

Question
   ↓
Embedding
   ↓
Qdrant Search
   ↓
Relevant Chunks
   ↓
LLM
   ↓
Answer

fileciteturn0file0L307-L347

Embeddings

An embedding is a numerical representation of text:

"Artificial Intelligence..."
          ↓
[0.23, -0.41, 0.82, ...]

These vectors can be stored in Qdrant. fileciteturn0file0L664-L674

Qdrant's Role

Think of Qdrant as the searchable memory of your RAG application.

🐳 5. Docker

Docker is different from LangChain and RAG.

Docker is a containerization platform. fileciteturn0file0L368-L374

If your application requires:

Python 3.12
Qdrant
PostgreSQL
Redis
Node.js
Specific libraries
Specific versions

another computer may have different versions or missing dependencies. Docker helps package and run services consistently. fileciteturn0file0L376-L409

Container

A container is a small isolated environment containing everything a particular service needs to run.

Your Computer
│
├── Docker
├── Container 1 → Qdrant
├── Container 2 → Backend
└── Container 3 → Database

Containers are isolated but can communicate. fileciteturn0file0L413-L437

📄 6. docker-compose.yml

A docker-compose.yml file tells Docker what services an application needs and how they should run. fileciteturn0file0L476-L498

Example:

services:

  qdrant:
    image: qdrant/qdrant
    ports:
      - "6333:6333"

Conceptually:

Docker
  ↓
Create Qdrant Container
  ↓
Use qdrant/qdrant Image
  ↓
Expose Port 6333

Run it with:

docker compose up

fileciteturn0file0L500-L541

🔗 7. Pipeline

A pipeline is a sequence of connected steps.

Step 1
  ↓
Step 2
  ↓
Step 3
  ↓
Final Result

In an AI application:

User Question
      ↓
Process Question
      ↓
Search Knowledge
      ↓
Get Relevant Information
      ↓
Send to LLM
      ↓
Generate Answer
      ↓
Show Answer

LangChain can help build this workflow. fileciteturn0file0L57-L78

📥 8. RAG Document Ingestion Pipeline

Before users ask questions, documents are prepared:

PDF
 ↓
Document Loader
 ↓
Text Extraction
 ↓
Text Splitting
 ↓
Chunks
 ↓
Embedding Model
 ↓
Vectors
 ↓
Qdrant

Example:

AI.pdf
   ↓
Chunk 1
"Artificial Intelligence enables..."

Chunk 2
"Machine learning is..."

Chunk 3
"Neural networks..."
   ↓
Create Embeddings
   ↓
Store in Qdrant

fileciteturn0file0L618-L689

🔎 9. RAG Query Pipeline

When a user asks a question:

User Question
      ↓
Query Embedding
      ↓
Search Qdrant
      ↓
Retrieve Relevant Chunks
      ↓
Build Prompt
      ↓
LLM
      ↓
Answer

fileciteturn0file0L694-L726

🔥 10. How Everything Works Together

For an AI chatbot that answers questions from PDFs:

                         USER
                           │
                           ▼
                     ┌───────────┐
                     │  Chat UI  │
                     └─────┬─────┘
                           │
                           ▼
                     ┌───────────┐
                     │  Backend  │
                     └─────┬─────┘
                           │
                           ▼
                     ┌───────────┐
                     │ LangChain │
                     └─────┬─────┘
                           │
                    ┌──────┴──────┐
                    ▼             ▼
              ┌──────────┐   ┌──────────┐
              │  Qdrant  │   │   LLM    │
              │ Vector DB│   │ GPT/etc. │
              └──────────┘   └──────────┘
                    ▲             ▲
                    └──────┬──────┘
                           ▼
                         ANSWER

The source describes this same relationship between the user, backend, LangChain, Qdrant, and LLM. fileciteturn0file0L545-L587

Docker can run services such as:

Docker
│
├── Backend Container
└── Qdrant Container

📊 11. Quick Comparison

Technology

Main Job

🧠 LLM

Generates the natural-language answer

📚 RAG

Retrieves relevant external information for the LLM

🔗 LangChain

Connects/orchestrates AI components

🗄️ Qdrant

Stores/searches vector embeddings

🐳 Docker

Runs services in isolated, reproducible containers

🔄 Pipeline

Sequence of connected processing steps

fileciteturn0file0L605-L614

🚀 12. Example: Chat With a PDF

Suppose you have:

AI.pdf

It contains:

"Artificial Intelligence enables machines to perform tasks that normally require human intelligence."

Step 1 — Load PDF

AI.pdf

Step 2 — Split into chunks

Chunk 1 → "Artificial Intelligence enables..."
Chunk 2 → "Machine learning is..."
Chunk 3 → "Neural networks..."

Step 3 — Create embeddings

"Artificial Intelligence..."
          ↓
[0.23, -0.41, 0.82, ...]

Step 4 — Store in Qdrant

Qdrant
├── Vector 1
├── Vector 2
└── Vector 3

Step 5 — User asks

"What is artificial intelligence?"

Step 6 — Search Qdrant

Qdrant finds the relevant chunk.

Step 7 — LangChain builds the prompt

Use this context:

"Artificial Intelligence enables machines to perform
tasks that normally require human intelligence."

Question:

"What is artificial intelligence?"

Step 8 — LLM answers

Artificial Intelligence is the ability of machines to perform tasks that typically require human intelligence.

This is the RAG application flow described in the source. fileciteturn0file0L618-L728

🤖 13. RAG and Agentic AI

Traditional RAG:

Question
   ↓
Retrieve Information
   ↓
LLM
   ↓
Answer

Agentic AI can dynamically choose tools:

User
 ↓
AI Agent
 ↓
Understand Task
 ↓
Choose Tool
 ├── Search Web
 ├── Query Database
 ├── Run Code
 ├── Read PDF
 ├── Call API
 └── Use RAG
 ↓
Evaluate Result
 ↓
Maybe Use Another Tool
 ↓
Final Answer

RAG can be one of the tools an AI agent uses. fileciteturn0file0L732-L778

🎯 14. Interview-Ready Definitions

LangChain

LangChain is a framework for building LLM-powered applications by connecting and orchestrating components such as models, prompts, documents, retrievers, tools, vector databases, and agents.

RAG

RAG, or Retrieval-Augmented Generation, is an architecture where relevant external information is retrieved and provided to an LLM as context before generating an answer.

Qdrant

Qdrant is a vector database used to store and search embeddings, making it useful for the retrieval stage of RAG systems.

Docker

Docker is a containerization platform used to package and run application services in isolated, reproducible environments.

Pipeline

A pipeline is a sequence of connected processing steps where the output of one step becomes the input of the next.

🧠 15. Ultimate Mental Model

🧠 LLM
= Brain

📚 RAG
= Give the brain relevant external knowledge

🔗 LangChain
= Connect and orchestrate the components

🗄️ Qdrant
= Searchable memory/storage for vector embeddings

🐳 Docker
= Package and run application services consistently

🔄 Pipeline
= Step 1 → Step 2 → Step 3 → Result

This mental model is summarized directly by the source material. fileciteturn0file0L782-L798

🔥 One-Line Architecture

PDF
 ↓
Chunks
 ↓
Embeddings
 ↓
Qdrant
 ↓
Retrieve Relevant Information
 ↓
LangChain
 ↓
LLM
 ↓
Answer

Docker can run the required services:

Docker
 ├── Backend
 └── Qdrant

📝 16. Quick Revision Checklist

What does LLM mean?

What is LangChain?

Is LangChain an LLM?

What does RAG stand for?

What are Retrieval, Augmentation, and Generation?

Why do we need RAG?

What is an embedding?

What is Qdrant?

Why is Qdrant useful in RAG?

What is Docker?

What is a Docker container?

What is docker-compose.yml?

What does docker compose up do?

What is a pipeline?

How do LangChain, RAG, Qdrant, Docker, and an LLM fit together?

How can RAG be used by an AI agent?

🏆 Final Summary

                    YOUR DOCUMENTS
                         │
                         ▼
                    RAG SYSTEM
                         │
              ┌──────────┴──────────┐
              ▼                     ▼
          Embeddings             Question
              │                     │
              ▼                     ▼
            QDRANT ◄──────────── Search
              │
              ▼
      Relevant Information
              │
              ▼
          LANGCHAIN
              │
              ▼
             LLM
              │
              ▼
            ANSWER

       🐳 DOCKER RUNS THE SERVICES

⭐ The Most Important Sentence

RAG finds the right information, Qdrant stores/searches the vectors, LangChain connects the workflow, the LLM generates the answer, and Docker runs the application's services.