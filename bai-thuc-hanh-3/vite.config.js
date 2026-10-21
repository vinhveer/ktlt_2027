import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

// base './' để bản build chạy được khi đặt trong thư mục con (vd: /bai-thuc-hanh-3/dist/)
export default defineConfig({
  base: './',
  plugins: [react()],
})
